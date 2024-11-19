#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct player
{
    char* name;
    int health;
    int items[5];
    int item_sum;
    int rounds_won;
};
void display(struct player* p)
{
    printf("Player name: %s\n",p->name);
    printf("Health: %d\n",p->health);
    printf("Lens: %d, Knife: %d\n",p->items[0], p->items[1]);
    printf("Beer: %d, Cigarette: %d\n",p->items[2], p->items[3]);
    printf("Handcuffs: %d\n\n",p->items[4]);
}
void display_instructions()
{
    printf("INSTRUCTIONS\n\n");
    printf("This is Buckshot Roulette\n\n");
    printf("You know the game already\n");
    printf("Here's how to give inputs\n");
    printf("Whenever you are asked to make a choice you are supposed to enter 'shoot', 'lens', 'knife', 'beer', 'cigarette', or 'handcuffs'\n");
    printf("If you select 'shoot' you will have to select who to shoot. Enter 'me' or 'opponent'\n");
    printf("Stats are displayed everytime\n");
    printf("If you do something wrong then 'Invalid choice' will be written above current stats and you have to make choice again\n");
    printf("It's a 2 player game. So get your friend and play against each other\n");
    printf("Goodluck\n\n");
}
void giveItems(struct player* p, int item_num)
{
    int index;
    for(int i=0;i<item_num;i++)
    {
        index=rand()%5;
        if(p->items[index]==3)
        {
            i--;
            continue;
        }
        p->items[index]++;
        p->item_sum++;
        if(p->item_sum==8)
            break;
    }
}
int fillGun(int* gun, int total)
{
    int lives,blanks;
    if(total%2!=0)
        lives = (rand()%2)+(total/2);
    else
        lives = total/2;
    blanks = total - lives;
    int l=0;
    for(int i=0;i<total;i++)
        gun[i]=-1;
    int index;
    while(l<lives)
    {
        index = rand()%total;
        if(gun[index]==-1)
        {
            gun[index]=1;
            l++;
        }
    }
    while(l<total)
    {
        index = rand()%total;
        if(gun[index]==-1)
        {
            gun[index]=0;
            l++;
        }
    }
    return lives;
}

int main()
{
    display_instructions();
    struct player* p[2];
    for(int i=0;i<2;i++)
    {
        p[i]=(struct player*)malloc(sizeof(struct player));
        p[i]->name=(char*)malloc(11*sizeof(char));
        p[i]->item_sum=0;
        p[i]->health=2;
        p[i]->rounds_won=0;
        for(int j=0;j<5;j++)
            p[i]->items[j]=0;
        printf("Player %d enter your name: ",i+1);
        scanf("\n%s",p[i]->name);
    }
    printf("\n");
    srand(time(0));
    int item_num=0,round=1;
    int gun[8];
    int total_shots, total_health=2;
    int lives,blanks,i=0;
    int n;
    printf("How many rounds do you want to play? ");
    scanf("%d",&n);
    printf("\n");
    while(round<=n)
    {
        if(item_num!=0)
            printf("We get %d items each\n",item_num);
        giveItems(p[0],item_num);
        giveItems(p[1],item_num);
        total_shots = (rand()%6)+3;
        if(item_num==0)
            total_shots=3;
        lives = fillGun(gun,total_shots);
        blanks = total_shots - lives;
        printf("Bullets are inserted in a random order\n");
        printf("%d Lives, %d Blanks\n",lives, blanks);
        printf("\n");
        int bullet=0,hc=0;
        char choice[10];
        while(bullet<total_shots)
        {
            printf("------------------------------\n\n");
            display(p[0]);
            display(p[1]);
            printf("------------------------------\n\n");
            printf("%s's turn:\n",p[i]->name);
            printf("Make a choice: ");
            scanf("%s",choice);
            if(strcmp(choice,"shoot")==0)
            {
                printf("Who to shoot? ");
                scanf("%s",choice);
                if(strcmp(choice,"opponent")==0)
                {
                    if(gun[bullet])
                        printf("It was a live!\n");
                    else
                        printf("It was a blank!\n");
                    p[(i+1)%2]->health-=gun[bullet];
                    if(hc<2)
                        i=(i+1)%2;
                    bullet++;
                    if(hc>0)
                        hc--;
                }
                else if(strcmp(choice,"me")==0)
                {
                    if(gun[bullet])
                        printf("It was a live!\n");
                    else
                        printf("It was a blank!\n");
                    p[i]->health-=gun[bullet];
                    if(gun[bullet])
                    {
                        if(hc<2)
                            i=(i+1)%2;
                        if(hc>0)
                            hc--;
                    }
                    bullet++;
                }
                else
                {
                    printf("\nInvalid choice\n\n");
                    continue;
                }
            }
            else if(strcmp(choice,"lens")==0)
            {
                if(p[i]->items[0]==0)
                {
                    printf("\nInvalid choice\n\n");
                    continue;
                }
                p[i]->items[0]--;
                p[i]->item_sum--;
                if(gun[bullet])
                    printf("It's a live\n");
                else
                    printf("It's a blank\n");
            }
            else if(strcmp(choice,"knife")==0)
            {
                if(p[i]->items[1]==0)
                {
                    printf("\nInvalid choice\n\n");
                    continue;
                }
                p[i]->items[1]--;
                p[i]->item_sum--;
                if(gun[bullet])
                    gun[bullet]++;
            }
            else if(strcmp(choice,"beer")==0)
            {
                if(p[i]->items[2]==0)
                {
                    printf("\nInvalid choice\n\n");
                    continue;
                }
                p[i]->items[2]--;
                p[i]->item_sum--;
                if(gun[bullet])
                    printf("Removed live shot\n");
                else
                    printf("Removed blank shot\n");
                bullet++;
            }
            else if(strcmp(choice,"cigarette")==0)
            {
                if(p[i]->items[3]==0)
                {
                    printf("\nInvalid choice\n\n");
                    continue;
                }
                p[i]->items[3]--;
                p[i]->item_sum--;
                if(p[i]->health!=total_health)
                    p[i]->health++;
            }
            else if(strcmp(choice,"handcuffs")==0)
            {
                if(p[i]->items[4]==0 || hc!=0)
                {
                    printf("\nInvalid choice\n\n");
                    continue;
                }
                p[i]->items[4]--;
                p[i]->item_sum--;
                hc=2;
            }
            else
            {
                printf("\nInvalid choice\n\n");
                continue;
            }
            printf("\n");

            if(p[0]->health<=0)
            {
                p[0]->health=0;
                break;
            }
            if(p[1]->health<=0)
            {
                p[1]->health=0;
                break;
            }
        }

        if(item_num<4)
            item_num+=2;

        if(p[0]->health==0)
        {
            printf("%s wins the round\n",p[1]->name);
            round++;
            i=1;
            p[1]->rounds_won++;
            total_health=4;
            p[0]->health=total_health;
            p[1]->health=total_health;
        }
        if(p[1]->health==0)
        {
            printf("%s wins the round\n",p[0]->name);
            round++;
            i=0;
            p[0]->rounds_won++;
            total_health=4;
            p[0]->health=total_health;
            p[1]->health=total_health;
        }
        printf("\n-----------------------------------\n\n");
    }
    if(p[0]->rounds_won>p[1]->rounds_won)
        printf("%s won the match\n%s takes the money\n",p[0]->name,p[0]->name);
    else if(p[0]->rounds_won<p[1]->rounds_won)
        printf("%s won the match\n%s takes the money\n",p[1]->name,p[1]->name);
    else
        printf("It's a draw\nPlay again to find out who takes the money\n");
    return 0;
}
// 0 = lens
// 1 = knife
// 2 = beer
// 3 = cigarette
// 4 = handcuffs