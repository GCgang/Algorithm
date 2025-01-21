// https://school.programmers.co.kr/learn/courses/30/lessons/76501

// map, reduce
// function solution(absolutes, signs) {
//     const result = absolutes.map((num, i) => signs[i] ? num : -num)

//     return result.reduce((acc, cur) => acc + cur, 0);
// }

// reduce
function solution(absolutes, signs) {
  return absolutes.reduce((acc, cur, i) => acc + (signs[i] ? cur : -cur), 0);
}
