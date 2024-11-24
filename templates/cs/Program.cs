using static System.Console;
int i=3,n;while(!int.TryParse(ReadLine(),out n))i--;n+=i;
if(n%3<1)Write("Fizz");
if(n%5<1)Write("Buzz");
if(n%3>0&&n%5>0)Write(n);



//Write((n%3<1?"Fizz":"")+(n%5<1?"Buzz":n%3>0?n:""));