/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const root = new Map();
    const RES_KEY = Symbol('result');
    
    return function(...args) {
        let curr = root;

        for (const arg of args) {
            if (!curr.has(arg)) {
                curr.set(arg, new Map());
            }
            curr = curr.get(arg);
        }

        if (curr.has(RES_KEY)) {
            return curr.get(RES_KEY);
        }

        const result = fn(...args);
        curr.set(RES_KEY, result);
        return result;

        
    };
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */