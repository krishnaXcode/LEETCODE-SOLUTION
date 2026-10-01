/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    if (n === 0) return arr;
    
    const result = [];
    
    function helper(currentArr, currentDepth) {
        for (const item of currentArr) {
            if (Array.isArray(item) && currentDepth < n) {
                helper(item, currentDepth + 1);
            } else {
                result.push(item);
            }
        }
    }
    
    helper(arr, 0);
    return result;
    
};