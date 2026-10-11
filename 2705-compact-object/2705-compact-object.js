/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (obj === null || typeof obj !== 'object') {
        return obj;
    }

    if (Array.isArray(obj)) {
        return obj.reduce((acc, curr) => {
            const compacted = compactObject(curr);
            if (Boolean(compacted)) {
                acc.push(compacted);
            }
            return acc;
        }, []);
    }

    const compactedObj = {};
    for (const key in obj) {
        const compacted = compactObject(obj[key]);
        if (Boolean(compacted)) {
            compactedObj[key] = compacted;
        }
    }
    return compactedObj;
};