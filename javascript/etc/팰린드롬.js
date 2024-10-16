// 앞으로 & 뒤로 읽었을 때 같은 문자열
// level, eye, hannah

function checkPalindrome(str) {
  return str === str.split('').reverse().join('');
}

console.log(checkPalindrome('level')); // true
console.log(checkPalindrome('eye')); // true
console.log(checkPalindrome('hannah')); // true
console.log(checkPalindrome('aabb')); // false
console.log(checkPalindrome('bbaadd')); // false

// 투포인터 구현
function checkPalindrome2(str) {
  const len = str.length;
  const mid = Math.floor(len / 2);
  for (let i = 0; i < mid; ++i) {
    if (str.charAt(i) !== str.charAt(len - 1 - i)) {
      return false;
    }
  }
  return true;
}

console.log(checkPalindrome2('level')); // true
console.log(checkPalindrome2('eye')); // true
console.log(checkPalindrome2('hannah')); // true
console.log(checkPalindrome2('aabb')); // false
console.log(checkPalindrome2('bbaadd')); // false
