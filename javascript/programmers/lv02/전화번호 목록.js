// https://school.programmers.co.kr/learn/courses/30/lessons/42577
// O(N)
function solution(phone_book) {
  let phoneMap = new Map();

  for (let phoneNumber of phone_book) {
    phoneMap.set(phoneNumber, true);
  }

  for (let phoneNumber of phone_book) {
    let prefix = '';
    for (let char of phoneNumber) {
      prefix += char;
      if (prefix !== phoneNumber && phoneMap.has(prefix)) {
        return false;
      }
    }
  }

  return true;
}

// O N log N
function solution2(phone_book) {
  phone_book.sort();

  for (let i = 0; i < phone_book.length - 1; i++) {
    if (phone_book[i + 1].startsWith(phone_book[i])) {
      return false;
    }
  }
  return true;
}
