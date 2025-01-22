// https://school.programmers.co.kr/learn/courses/30/lessons/12950
// function solution(arr1, arr2) {
//     const result = [];
//     for (let i = 0; i < arr1.length; i++) {
//         const row = [];
//         for (let j = 0; j < arr1[i].length; j++) {
//             row.push(arr1[i][j] + arr2[i][j]);
//         }
//         result.push(row);
//     }
//     return result
// }

function solution(arr1, arr2) {
  return arr1.map((row, i) => row.map((val, j) => val + arr2[i][j]));
}
