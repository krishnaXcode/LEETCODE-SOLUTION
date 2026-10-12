/**
 * @param {Generator} generator
 * @return {[Function, Promise]}
 */

    var cancellable = function(generator) {
    let cancelIt;
    
    const promise = new Promise((resolve, reject) => {
        cancelIt = () => {
            try {
                const res = generator.throw("Cancelled");
                handle(res);
            } catch (err) {
                reject(err);
            }
        };

        const handle = (result) => {
            if (result.done) {
                resolve(result.value);
                return;
            }
            
            Promise.resolve(result.value)
                .then(val => {
                    try {
                        handle(generator.next(val));
                    } catch (err) {
                        reject(err);
                    }
                })
                .catch(err => {
                    try {
                        handle(generator.throw(err));
                    } catch (e) {
                        reject(e);
                    }
                });
        };

        try {
            handle(generator.next());
        } catch (err) {
            reject(err);
        }
    });

    return [cancelIt, promise];
};
    


/**
 * function* tasks() {
 *   const val = yield new Promise(resolve => resolve(2 + 2));
 *   yield new Promise(resolve => setTimeout(resolve, 100));
 *   return val + 1;
 * }
 * const [cancel, promise] = cancellable(tasks());
 * setTimeout(cancel, 50);
 * promise.catch(console.log); // logs "Cancelled" at t=50ms
 */