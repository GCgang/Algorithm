function solution(want, number, discount) {
  let count = 0;

  for (let i = 0; i <= discount.length - 10; i++) {
    let isMatch = true;
    const tempDiscount = discount.slice(i, i + 10);
    const wantMap = new Map();

    for (let j = 0; j < want.length; j++) {
      wantMap.set(want[j], number[j]);
    }

    for (const item of tempDiscount) {
      if (wantMap.has(item)) {
        wantMap.set(item, wantMap.get(item) - 1);
      }
    }

    for (const value of wantMap.values()) {
      if (value > 0) {
        isMatch = false;
        break;
      }
    }

    if (isMatch) {
      count++;
    }
  }
  return count;
}
