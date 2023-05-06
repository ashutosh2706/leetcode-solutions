/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var x = null;
    return ()=> {
        if(x == null) x = n;
        return x++;
    }
};