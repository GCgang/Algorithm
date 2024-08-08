function solution(decimal) {
  const stack = [];

  while (decimal > 0) {
    stack.push(decimal % 2);
    decimal = Math.floor(decimal / 2);
  }

  let binary = '';
  while (stack.length > 0) {
    binary += stack.pop();
  }
  return binary;

  // return stack.reverse().join('');
}

console.log(solution(10)); // 1010
console.log(solution(13)); // 1101
console.log(solution(27)); // 11011
console.log(solution(100)); // 1100100
console.log(solution(12345)); // 11000000111001
