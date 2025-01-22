// https://school.programmers.co.kr/learn/courses/30/lessons/82612
// 반복문 풀이
// function solution(price, money, count) {
//     let cost = 0;

//     for(let i = 1; i <= count; i++) {
//         cost += price * i;
//     }

//     return Math.max(0, cost - money)
// }

// 등차수열 합 공식 풀이
function solution(price, money, count) {
  const cost = ((price + price * count) * count) / 2;
  return Math.max(0, cost - money);
}
