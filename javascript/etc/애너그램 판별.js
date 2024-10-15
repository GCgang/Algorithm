const strA = 'listen';
const strB = 'silent';

// #1 split, sort, join
// function isAnagram(strA, strB) {
//   if (strA.length !== strB.length) return false;

//   return strA.split('').sort().join() === strB.split('').sort().join();
// }

// #2 map
function isAnagram(strA, strB) {
  if (strA.length !== strB.length) return false;

  const hashMap = {};
  for (const char of strA) {
    hashMap[char] = hashMap[char] ? hashMap[char] + 1 : 1;
  }

  for (const char of strB) {
    if (!hashMap[char]) {
      return false;
    }
    hashMap[char]--;
  }
  return true;
}
console.log(isAnagram(strA, strB));
