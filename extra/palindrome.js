function pd(str) {
    let i = 0 , j = str.length -1;
    while (i<=j) {
        if (str[i++]!==str[j--]) {
            return "Its not palindrome";
        }
    }
    return "Its palindrome";
}

console.log(pd("lun"));
