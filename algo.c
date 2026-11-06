#include <stdio.h>
#define N 50 /*number of students*/
#define M 10 /*number of subjects*/
#define L 30 /*length of strings*/
int main()
{
int n,m,i,j;
int choice;
char name[N][L],lastname[N][L],subject[M][L];
int coif[M], id[N];
float note[N][M];
/*entring the number of students and subjects*/
  do {
    printf("enter the number of students:");
      scanf("%d",&n);
    }
  while(n <= 0 || n > N);/*condition so it repeats till the n<=50 and n>0*/

 do {
    printf("enter the number of subjects:");
      scanf("%d",&m);
    }
  while(m <= 0 || m> M);
/*Saisie des données :*/
for(j=0;j<m;j++)
  {
   printf("subject %d\n",j+1);
   printf("subject name:");
   scanf("%s",subject[j]);
     do{
      printf("cofecient:");
      scanf("%d",&coif[j]);
     }
    while(coif[j]>5 || coif[j]<1);
  }
for(i=0;i<n;i++)
{
 printf("student %d\n",i+1);
 printf("name:");
 scanf("%s",name[i]);
 printf("last name:");
 scanf("%s",lastname[i]);
 printf("id:");
 scanf("%d",&id[i]);

  for(j=0;j<m;j++){
    do{
    printf("note of %s:",subject[j]);
    scanf("%f",&note[i][j]);
    }
    while(note[i][j]<0 || note[i][j]>20);
  }
/*Affichage d'un aperçu des étudiants et matières.*/
}
for(i=0;i<n;i++){
printf("student %d\n",i+1);
printf("name: %s\n",name[i]);
printf("last name: %s\n",lastname[i]);
printf("identification:%d\n",id[i]);
 for(j=0;j<m;j++){
 printf("subject:%s\n",subject[j]);
 printf("coefficientof the subject:%d\n",coif[j]);
 printf("note:%f\n",note[i][j]);
 }
}
/*Calculs et statistiques*/
/*Moyenne pondérée par étudiant*/
float avreageperstudent[N];
float s,sumcoif;
for(i=0;i<n;i++)
{
s=0;sumcoif=0;
  for(j=0;j<m;j++){
   s=s+note[i][j]*coif[j];
   sumcoif=sumcoif+coif[j];
  }
avreageperstudent[i]=s/sumcoif;
}
/*Moyenne générale par matière*/
float sumnotes,avreagepersubject[M];
for(j=0;j<m;j++){
 sumnotes=0;
for(i=0;i<n;i++)
{
  sumnotes=sumnotes+note[i][j];
}
avreagepersubject[j]=sumnotes/n;
}
/*Moyenne générale globale*/
float avreagesum,generalavreage;
avreagesum=0;
for(i=0;i<n;i++)
{
 avreagesum=avreagesum+avreageperstudent[i];
}
 generalavreage=avreagesum/n;
/*Meilleure et pire note par étudiant et par matière*/
/*for each student*/
float bestnoteperstudent[N],worstnoteperstudent[N];
 for(i=0;i<n;i++)
 {
  bestnoteperstudent[i] = note[i][0];
 worstnoteperstudent[i] = note[i][0];
  for(j=1;j<m;j++)
   if(note[i][j] > bestnoteperstudent[i])
   {
    bestnoteperstudent[i]=note[i][j];
   } else{
    if(note[i][j] < worstnoteperstudent[i])
     {
      worstnoteperstudent[i]=note[i][j];
     }
    }
 }
/*persubject*/
float bestnotepersubject[M],worstnotepersubject[M];
 for(j=0;j<m;j++)
 {
  bestnotepersubject[j]=note[0][j];
  worstnotepersubject[j]=note[0][j];
  for(i=1;i<n;i++)
   if(note[i][j] > bestnotepersubject[j])
   {
    bestnotepersubject[j]=note[i][j];

     if(note[i][j] < worstnotepersubject[j])
     {
      worstnotepersubject[j] = note[i][j];
     }
    }
 }


/*Classement des étudiants par moyenne pondérée*/
int classement[N],index;
for(i = 0; i < n; i++)
    classement[i] = i;
for(i = 0; i < n-1; i++)
{
    for(j = i+1; j < n; j++)
    {
        if(avreageperstudent[classement[i]] < avreageperstudent[classement[j]])
        {
            index = classement[i];
            classement[i] = classement[j];
            classement[j] = index;
        }
    }
}
/*Liste des étudiants n’ayant pas eu la moyenne*/
printf("Students who failed:\n");
for(i=0;i<n;i++){
 if(avreageperstudent[i]<10)
 {
  printf("%s %s (ID: %d) -,Average: %f\n",name[i], lastname[i], id[i], avreageperstudent[i]);
  }
 }
/*Gestion dynamique dans le menu*/

do {
    printf("\nMENU\n");
    printf("1. Display students\n");
    printf("2. Statistics\n");
    printf("3. Add student\n");
    printf("4. Modify student\n");
    printf("5. Delete student\n");
    printf("6. Search student by ID\n");
    printf("0. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (i = 0; i < n; i++) {
            printf("\nStudent %d\n", i + 1);
            printf("Name: %s %s\n", name[i], lastname[i]);
            printf("ID: %d\n", id[i]);
            for (j = 0; j < m; j++)
                printf("%s: %.2f\n", subject[j], note[i][j]);
            printf("Average: %.2f\n", avreageperstudent[i]);
        }
    }

    else if (choice == 2) {
        for (i = 0; i < n; i++)
            printf("%s %s: %.2f\n",
                   name[i], lastname[i], avreageperstudent[i]);

        printf("General average: %.2f\n", generalavreage);

        printf("Failed students:\n");
        for (i = 0; i < n; i++)
            if (avreageperstudent[i] < 10)
                printf("%s %s (ID %d)\n",
                       name[i], lastname[i], id[i]);
    }

    else if (choice == 3 && n < N) {
        scanf("%s", name[n]);
        scanf("%s", lastname[n]);
        scanf("%d", &id[n]);

        for (j = 0; j < m; j++)
            scanf("%f", &note[n][j]);

        float s = 0, sumcoif = 0;
        for (j = 0; j < m; j++) {
            s += note[n][j] * coif[j];
            sumcoif += coif[j];
        }
        avreageperstudent[n] = s / sumcoif;
        n++;
    }

    else if (choice == 4) {
        int searchId, found = -1;
        scanf("%d", &searchId);

        for (i = 0; i < n; i++)
            if (id[i] == searchId)
                found = i;

        if (found != -1) {
            for (j = 0; j < m; j++)
                scanf("%f", &note[found][j]);

            float s = 0, sumcoif = 0;
            for (j = 0; j < m; j++) {
                s += note[found][j] * coif[j];
                sumcoif += coif[j];
            }
            avreageperstudent[found] = s / sumcoif;
        }
    }

    else if (choice == 5) {
        int searchId, found = -1;
        scanf("%d", &searchId);

        for (i = 0; i < n; i++)
            if (id[i] == searchId)
                found = i;

        if (found != -1) {
            for (i = found; i < n - 1; i++) {
                for (j = 0; j < L; j++) {
                    name[i][j] = name[i + 1][j];
                    lastname[i][j] = lastname[i + 1][j];
                }
                id[i] = id[i + 1];
                avreageperstudent[i] = avreageperstudent[i + 1];
                for (j = 0; j < m; j++)
                    note[i][j] = note[i + 1][j];
            }
            n--;
        }
    }

    else if (choice == 6) {
        int searchId, found = -1;
        scanf("%d", &searchId);

        for (i = 0; i < n; i++)
            if (id[i] == searchId)
                found = i;

        if (found != -1)
            printf("%s %s %.2f\n",
                   name[found], lastname[found], avreageperstudent[found]);
    }

} while (choice != 0);



    return 0;
    }

