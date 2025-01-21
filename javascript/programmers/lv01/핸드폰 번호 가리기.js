// https://school.programmers.co.kr/learn/courses/30/lessons/12948
// function solution(phone_number) {
//     let result = ''
//     for (let i = 0; i < phone_number.length; i++) {
//         if (i < phone_number.length - 4) {
//             result += '*'
//         } else {
//             result += phone_number[i];
//         }
//     }
//     return result;
// }

function solution(phone_number) {
  const hiddenLength = phone_number.length - 4;
  return '*'.repeat(hiddenLength) + phone_number.slice(-4);
}
