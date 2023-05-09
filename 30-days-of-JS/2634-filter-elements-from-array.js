/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let new_arr = []
    for(let i=0; i<arr.length; i++) 
        if(fn(arr[i], i))
            new_arr.push(arr[i])
    
    return new_arr
};