/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    let params = []
    return function curried(...args) {
        params = [...params, ...args]
        if(fn.length === params.length)
            return fn(...params)    // spread params array over fn as args
        else 
            return curried
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
