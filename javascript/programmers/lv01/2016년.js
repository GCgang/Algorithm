// https://school.programmers.co.kr/learn/courses/30/lessons/12901
function solution(a, b) {
  const days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT'];
  const date = new Date(2016, a - 1, b);
  return days[date.getDay()];
}

// 다른 풀이

// function solution2(a, b) {
//     const days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];

//     // 윤년 확인 함수
//     function isLeapYear(year) {
//         return (year % 4 === 0 && year % 100 !== 0) || (year % 400 === 0);
//     }

//     const year = 2016; // 문제에서 주어진 연도
//     const daysInMonth = isLeapYear(year)
//         ? [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] // 윤년
//         : [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; // 평년

//     let totalDays = 0;

//     // 1월부터 (a-1)월까지의 일수 합산
//     for (let i = 0; i < a - 1; i++) {
//         totalDays += daysInMonth[i];
//     }

//     // 해당 월의 일수 추가
//     totalDays += b;

//     // 2016년 1월 1일은 금요일이므로 5일 추가(0=SUN, 1=MON, ..., 5=FRI)
//     const dayIndex = (totalDays + 4) % 7;

//     return days[dayIndex];
// }
