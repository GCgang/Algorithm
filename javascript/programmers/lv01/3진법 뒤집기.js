// https://school.programmers.co.kr/learn/courses/30/lessons/68935
// function solution(n)  {
//     const base = 3;
//     let reversed = '';

//     while(n) {
//         reversed += n % base;
//         n = Math.floor(n / base);
//     }
//     let result = 0;
//     let power = 0;

//     for (let i = 0; i < reversed.length; i++) {
//         result += Number(reversed[i]) * Math.pow(base, reversed.length - 1 - i);
//     }

//     return result
// }

function solution(n) {
  let ternary = n.toString(3);

  let reversed = ternary.split('').reverse().join('');

  let result = parseInt(reversed, 3);

  return result;
}
