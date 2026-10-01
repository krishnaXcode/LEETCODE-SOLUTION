  /**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    // 1. Validate total element count
    if (rowsCount * colsCount !== this.length) {
        return [];
    }

    // 2. Initialize an empty 2D matrix
    const matrix = Array.from({ length: rowsCount }, () => new Array(colsCount));

    // 3. Populate matrix column by column
    for (let i = 0; i < this.length; i++) {
        const col = Math.floor(i / rowsCount);
        
        // Even columns move top -> bottom, odd columns move bottom -> top
        const row = col % 2 === 0 
            ? i % rowsCount 
            : rowsCount - 1 - (i % rowsCount);

        matrix[row][col] = this[i];
    }

    return matrix;
};