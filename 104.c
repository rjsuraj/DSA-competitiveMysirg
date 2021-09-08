// 104. calculate extra profit.
// Statement:sumit has a gift shop. He has great collections of show pieces in his shop. One day by mistake his employee sold k single piece

// of an art piece item which should be sold as paired only. so the pairs of that art piece get disturbed.

// At the same time sumit realizes that the single piece purchasing is more popular in peoples so he can sell unpaired art piece also.

// and this type ofpurchasing is more popular among peoples so he decided to slightly increase the price of single piece.

// he fixed the price like, if pair selling cost is x then single piece will be sold at price x/2+10.

// So if art piece is available in pair he will sell the pair but if it is single piece he will sell it according to above mentioned price.

// Using this approach he made profit more than if he sell art pieces as pair.

// Your task is to first arrange the art pieces pair wise so that he know how many unpaired pieces are there and calculate the

// extra profit he can made by using above approach.

// You should make pair of that art piece first which comes first in original array.

// For example if array A= acbdaabcde then make first pair of a then c then b and so on.

// At last remaining art pieces also should arranged in order as they appear in original array that means

// Relative positioning should be maintained in rearranged array. so after rearrangement array A should look like aaccbbddae

// Input: first line contains two integers n and p where n denoting number of single art piece(not pair)

// and p denoting price of a pair of art piece.

// Second line contains n space separated characters denoting n single art pieces.

// Output: first line contains n characters denoting rearranged pairs of art pieces

// Second line contains extra profit he made by selling single pieces of art piece

// Constraint:2<=n<=20

// 100<=p<=1000

// Example:

// 10 100

// abcdaabcde

// aabbccddae

// 20

// Test Case 1

// Input:
// 10 100
// abcdaabcde


// Output:
// aabbccddae
// 20

// Test Case 2

// Input:
// 14 120
// abcbgdehabcdei


// Output:
// aabbccddeeghbi
// 40


main()
{
  //write your code here
  int n,p;
  scanf("%d%d",&n,&p);
  char s[n];
  int i;
  scanf("%c",&s[0]);
  for(i=0;i<n;i++)
    scanf("%c",&s[i]);
   
  int j,k=0,count=0;
  char ch,first=0;
  for(i=0;i<n;i++)
  {
      for(j=i+1;j<n;j++)
      {
        if(s[i]==s[j])
        {
          i+=1;
          for(j=j;j>=i;j--)
            s[j]=s[j-1];
          break;
        }
      }
      if(s[i]==first)
        break;
      if(j==n && s[i]!=first)
      {
        if(count==0)
          first=s[i];
        ch=s[i];
        for(j=i;j<n-1;j++)
          s[j]=s[j+1];
        s[n-1]=ch;
        i-=1;
        count+=1;
      }  
  }
  for(i=0;i<n;i++)
    printf("%c",s[i]);
  for(i=1;i<=count;i++)
    k=k+10;
  printf("\n%d",k);
}
