/**
 * @param {Function} fn
 */
function memoize(fn) {

    let map = {}
    return function(...args) {
        if(arguments.length == 2) {
            let obj = [arguments[0], arguments[1]]
            if(obj in map) return map[obj];
            else return map[obj] = fn(arguments[0], arguments[1])

        } else {
            if(arguments[0] in map) return map[arguments[0]];
            else return map[arguments[0]] = fn(arguments[0]);
        }
        
    }
}