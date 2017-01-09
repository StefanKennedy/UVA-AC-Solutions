#include <stdio.h>
#include <string.h>

int main() {

  char a[11], b[11];
  while(scanf("%s %s\n", a, b) == 2){
    if(a[0] == b[0] && a[0] == '0'){
      break;
    }
    int n1 = strlen(a);
    int n2 = strlen(b);
    int count = 0;
    /* They;re not all going to be the same length */
    int carry = 0;
    int i;
    for(i = 0; (i < n1 && i < n2) || (carry && (i < n1 || i < n2)); i++){
      int twodigits = 0;
      if(i < n1 && i < n2){
        twodigits = (a[n1 - i - 1] - '0') + (b[n2 - i - 1] - '0');
      } else if(i < n1){
        twodigits = (a[n1 - i - 1] - '0');
      } else if(i < n2) {
        twodigits = (b[n2 - i - 1] - '0');
      }
      if(twodigits + carry > 9){
        count++;
        carry = 1;
      }else{
        carry = 0;
      }
    }
    if(count == 0) printf("No carry operation.\n");
    if(count == 1) printf("1 carry operation.\n");
    if(count > 1) printf("%d carry operations.\n", count);
  }
  return 0;
}
