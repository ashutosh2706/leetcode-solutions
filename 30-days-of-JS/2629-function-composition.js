/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        let n = functions.length
        let val = x
        for(let i = n-1; i>=0; i--) {
            let f = functions[i]
            val = f(val)
        }
        return val
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */