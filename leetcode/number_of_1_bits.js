/**
 ** @param {number} n - a positive integer
 ** @return {number}
 **/
var hammingWeight = function(n) {
    var num = 0;
    while (n > 0) {
        num += n % 2;
        n = Math.floor(n / 2);
    }
    return num;
};

console.log(hammingWeight(11));
