## 문제 (02.js)

02 배열 제어하기

- 정수 배열을 받아서, 배열의 중복값을 제거하고,
  배열 데이터를 내림차순으로 정렬해서 반환하는 solution() 함수 만들기

제약 조건

- 정수 배열의 길이: 2이상 1000이하
- 정수 배열의 각 데이터 값: -100,000이상 100,000 이하

권장 시간 복잡도: `O(N log N)`

## 풀이

`Set`을 사용하여 중복 값 제거

- `Set` 객체는 해시 알고리즘으로 데이터를 저장하므로 시간 복잡도 `O(N)`을 보장한다
- **해시 알고리즘 자체는 시간 복잡도 `O(1)` 이지만 배열의 원소 개수가 N인 경우 중복값을 제거하기 위해 배열을 한번 순회하고 삽입해야 하므로 시간 복잡도가 `O(N)`이 된다**

`sort()`함수 사용하여 **내림차순** 정렬

## Reference

- [MDN Set](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Set)
- [MDN 스프레드 연산자](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Operators/Spread_syntax)
- [MDN Array.prototype.sort()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)
