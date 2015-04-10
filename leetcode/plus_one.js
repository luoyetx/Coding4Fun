/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    digits.reverse();
    digits[0] += 1;
    c = 0;
    for (i=0; i<digits.length; i++) {
        c = digits[i] + c;
        digits[i] = c % 10;
        c = Math.floor(c / 10);
    }
    if (c > 0) {
        digits.push(c);
    }
    return digits.reverse();
};

// Test
console.log(plusOne([1,2,3]));
console.log(plusOne([9,9,9]));
