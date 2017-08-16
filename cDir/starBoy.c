#include<stdio.h>

int printStars(int starsTp, int spaceTp, int flag);

int main(){
	int stars = 0;
  	int loopLen = 0;
	int minLen = 0;
  	int maxLen = 0;
  	int index = 0;
	int space = 0;
	int space2 = 0;	
	int spaceIndex = 0;

  	scanf("%d",&stars);
  	maxLen = (float) stars*0.866;
	if((int)((float)maxLen - (int)maxLen))
	maxLen = (int) (maxLen + 1);
	else
	maxLen = (int)maxLen;

  	minLen = (float) (maxLen/3 +1);
	
	if((int)((float)minLen - (int)minLen))
	minLen = (int) (minLen + 1);
	else
	minLen = (int)minLen;

  	loopLen = maxLen + minLen;
        
	space = stars/2;

	space2 = space;
	spaceIndex = stars;
        printf("Stars %d MaxLen %d MinLen %d LoopLen %d Space %d\n", stars, maxLen, minLen, loopLen, space);
  	for ( index = 0; index < loopLen; index++ ) {
      		if(index == 0 || index == loopLen - 1) {
			printStars(0,space--,1);
			printStars(1,0,3);
		}
		if(index == minLen || index == maxLen) {
                        printStars(stars,0,3);
		}
		if(space == space2){
			space2++;
			printStars(0,space--,1);
			spaceIndex--;
			printStars(0,index-1,2);
		}
		if(index < minLen){
			printStars(0,space--,1);
			printStars(0,index-1,2);
		}
		if(index > minLen && space != space2 && index < maxLen){
			if(space > space2){
				printStars(0,space2, 1);
				printStars(1,0,4);
				printStars(0,space-space2,1);
				printStars(1,0,4);
				printStars(0,index-1,1);
				printStars(0,space-space2,2);
				space--;
				space2++;
			}else{
				printStars(0,space,1);
				printStars(1,0,4);
                                printStars(0,space2-space,1);
                                printStars(1,0,4);
                                printStars(0,spaceIndex--,1);
                                printStars(0,space2-space,2);
                                space--;
                                space2++;
			}
		}
		if(index > maxLen){
			printStars(0,space2++,1);
			spaceIndex = spaceIndex -1;
			printStars(0,spaceIndex,2);
		}
		
  	}
}

int printStars(int starsTp, int spaceTp, int flag) {
	fflush(stdout);
	if ( flag == 1 ) {
		while ( spaceTp > 0 ) {
			spaceTp = spaceTp - 1;
			printf(" ");
		}
	} else if ( flag == 2 ) {
		printf("*");
		while ( spaceTp > 0 ) {
			spaceTp = spaceTp - 1;
                        printf(" ");
                }
		printf("*");
		printf("\n");
	} else if ( flag == 3 ) {
                while ( starsTp > 0 ) {
			starsTp = starsTp - 1;
                        printf("*");
                }
		printf("\n");
        } else if( flag == 4 ) {
		while (starsTp > 0){
			starsTp = starsTp - 1;
			printf("*");
		}
	}
	fflush(stdout);
	return 1;
}
