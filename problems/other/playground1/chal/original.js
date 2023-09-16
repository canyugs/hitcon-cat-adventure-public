var cipher = ")+7'*(\x1CX\v\f\x1E\x1F\x0EZ\x1B\x15\x15-\x16\x19E\x02\x1E\x1BI\x14\x1C";
var key = "abcdefghijklmnopqrstuvwxyza";
var flag = "";
for(var i=0; i<27; i++){
    flag += String.fromCharCode(cipher.charCodeAt(i) ^ key.charCodeAt(i))
}
alert("Decrypted done");
