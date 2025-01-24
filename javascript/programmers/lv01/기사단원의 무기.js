// https://school.programmers.co.kr/learn/courses/30/lessons/136798

// O(n log n)
function solution(number, limit, power) {
  const divisorCounts = Array(number + 1).fill(0);

  for (let i = 1; i <= number; i++) {
    for (let j = i; j <= number; j += i) {
      divisorCounts[j]++;
    }
  }
  return divisorCounts.reduce((tot, cnt) => {
    return tot + (cnt > limit ? power : cnt);
  });
}

// // O(n root n)
// function solution(number, limit, power) {
//     const getDivisorCount = (num) => {
//         let count = 0;
//         for (let i = 1; i <= Math.sqrt(num); i++) {
//             if (num % i === 0) {
//                 count++;
//                 if (i !== num / i) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     };

//     let totalWeight = 0;

//     for (let i = 1; i <= number; i++) {
//         const divisorCount = getDivisorCount(i);
//         totalWeight += divisorCount > limit ? power : divisorCount;
//     }

//     return totalWeight;
// }
