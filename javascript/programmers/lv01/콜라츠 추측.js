// https://school.programmers.co.kr/learn/courses/30/lessons/12943
// 재귀적으로 풀기
function solution(num, count = 0) {
  if (count >= 500) return -1;
  if (num === 1) return count;

  if (num % 2 === 0) {
    return solution(num / 2, count + 1);
  } else {
    return solution(num * 3 + 1, count + 1);
  }
}

// function solution(num) {
//     let count = 0;

//     while(num !== 1) {
//         if (count >= 500) return -1;

//         if (num % 2 === 0) {
//             num /= 2;
//         } else {
//             num = num * 3 + 1;
//         }

//         count++;
//     }
//     return count;
// }
