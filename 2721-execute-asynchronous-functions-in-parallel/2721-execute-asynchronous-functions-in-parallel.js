var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        if (functions.length === 0) {
            resolve([]);
            return;
        }

        const res = new Array(functions.length);
        let resolvedCount = 0;
        let isRejected = false;

        functions.forEach((fn, index) => {
            fn()
                .then(value => {
                    if (isRejected) return;
                    res[index] = value;
                    resolvedCount++;
                    if (resolvedCount === functions.length) {
                        resolve(res);
                    }
                })
                .catch(error => {
                    if (isRejected) return;
                    isRejected = true;
                    reject(error);
                });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */