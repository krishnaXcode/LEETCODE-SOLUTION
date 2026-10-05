 /**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const res = {};

    for (const item of this) {
        const key = fn(item);
        if (!res[key]) {
            res[key] = [];
        }
        res[key].push(item);
    }

    return res;
};

/**
 * Example usage:
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */