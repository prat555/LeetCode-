Array.prototype.last = function() {
  if (this.length === 0) {
    return -1; // Or undefined, depending on desired behavior for empty arrays
  }
  return this[this.length - 1];
};