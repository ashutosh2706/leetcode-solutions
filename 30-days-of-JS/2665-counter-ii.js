/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var num = init
    var tmp = init

    return {

        increment: function() {
            return ++tmp;
        },

        decrement: function() {
            return --tmp;
        },

        reset: function() {
            return tmp = init
        }
    }

};