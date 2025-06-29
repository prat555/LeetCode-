/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeoutId; // Variable to store the timeout ID

    return function(...args) {
        // Clear any existing timeout to cancel the previous scheduled execution
        clearTimeout(timeoutId);

        // Set a new timeout
        timeoutId = setTimeout(() => {
            // Execute the original function 'fn' after 't' milliseconds
            // 'apply' is used to maintain the correct 'this' context and pass arguments
            fn.apply(this, args); 
        }, t);
    };
};