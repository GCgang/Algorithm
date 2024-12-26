## 문제 (01.js)

배열 정렬하기

- 정수 배열을 정렬해서 반환하는 solution() 함수 만들기

제약 조건

- 정수 배열의 길이: 2이상 10^5이하
- 정수 배열의 각 데이터 값: -100,000이상 100,000 이하

권장 시간 복잡도: `O(N log N)`

## 풀이

`sort()`함수 사용하여 **오름차순** 정렬

자바스크립트의 sort() 메서드는 아무런 조건을 전달하지 않고 실행하면 데이터가 문자열이라 가정하고 정렬한다.

- 첫 번째 인자 a가 두 번째 인자 b보다 앞에 나와야 한다면 음수 반환(**오름차순**)
- 첫 번째 인자 a가 두 번째 인자 b보다 뒤에 나와야 한다면 양수 반환(**내림차순**)
- 위치 변경을 하지 않는다면 0을 반환

## Reference

- [MDN Array.prototype.sort()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)
