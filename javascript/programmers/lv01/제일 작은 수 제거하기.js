// https://school.programmers.co.kr/learn/courses/30/lessons/12935

// function solution(arr) {
//     if (arr.length === 1) return [-1];

//     const min = Math.min(...arr);
//     const index = arr.indexOf(min);

//     arr.splice(index, 1);

//     return arr;
// }

// 중복이 있어도 동작
function solution(arr) {
  if (arr.length === 1) return [-1];

  const min = Math.min(...arr);

  return arr.filter((num) => num !== min);
}
