#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <random>

int main (int argc, char* argv[]) {
 if (argc != 8) {
	printf("\t\tInvalid number of arguments!\n\t\tPlease Provide\n\t\tOperating VDD\n\t\tDesigned minimum VDD\n\t\tSNM value\n\t\tCache size in Kilo Bytes and\n\t\tBlock size in Bytes\n\tOutput filename\n\tFilure probability outputfile\n");
	exit(1);
 }

 int failingsum = 0;
 int cachesize = 8*1024*atoi(argv[4]);
 int blksize=atoi(argv[5])*8;
 int numblks=cachesize/blksize;

 float snm,vdd;
 float vmin;
 float vddmin[numblks];
 float vddmin2[numblks];
 float snmmin[numblks];
 float vddblk = 1.0;
 float vddblk2 = 1.0;
 float fpblocks[numblks];

 double sigma = 0.015;
 double nor_dist;

 snm= atof ( argv[1] );
 vmin = atof (argv[2] );
 vdd = atof (argv[3] );

 //FILE *filep, *filefp; 

 /*filep = fopen ( argv[6], "w" );
 if ( filep == NULL ) {
    printf ( "Unable to open file %s\n",argv[6] );
    exit(1);
 }
  filefp = fopen ( argv[7], "w" );
 if ( filefp == NULL ) {
    printf ( "Unable to open file %s\n",argv[7] );
    exit(1);
 }*/

 printf("snm=%f vmin=%f vdd=%f cachesize=%d blocksize=%d vddfile=%s fpfile=%s\n", atof(argv[1]),atof( argv[2]), atof(argv[3]), atoi(argv[4]),atoi( argv[5]), argv[6], argv[7]);

 std::default_random_engine generator;
 std::default_random_engine cellgenerator;
 std::normal_distribution<double> distribution(snm,sigma);


 for ( int i = 0; i < numblks; i++ ) {
    nor_dist = distribution(generator);
    vddmin[i] = vdd;
    float cell_vddmin = vddmin[i];
    snmmin[i] = 0.0;
    float cell_snm = 1.0;
    float secondcell_snm=1.0;
    float secondvddmin;
    std::normal_distribution<double>celld(nor_dist,sigma);
    double cell_nor_dist;
    failingsum=0;
    double avgvdd, avgfp;
    avgvdd = avgfp = 0.0;
    //std::default_random_engine cellgenerator;
    for (int j=0; j < blksize;j++) {
	cell_nor_dist = celld(cellgenerator);
	 failingsum += (cell_nor_dist <= vmin) ? 1 : 0;
        if (cell_nor_dist < cell_snm) {
	    secondcell_snm = cell_snm;
	    secondvddmin = vdd-secondcell_snm-vmin;
	    cell_snm = cell_nor_dist;
            cell_vddmin = vdd-cell_nor_dist-vmin;
        }
    }
    snmmin[i] = cell_snm;
    vddmin[i] = cell_vddmin;
    vddmin2[i] = secondvddmin;
    //fprintf(filep,"%f\n",secondvddmin);
    fpblocks[i] = (float)failingsum/(blksize*10);
    //fprintf(filefp,"%f\n",fpblocks[i]);
 }
/* fclose(filep);
 fclose(filefp);*/
 /*vddblk=vddblk2=vddmin[0];
 for (int i=0;i < numblks;i++) {
    if (vddmin[i] > vddblk) {
	vddblk2 = vddblk;
	vddblk = vddmin[i];
    }
   else if (vddmin[i] > vddblk2 && vddmin[i] != vddblk)
        vddblk2 = vddmin[i];
 }*/
 float avgvmin, avgfp, avgsnm;
 float tmpvmin, tmpsnm,tmpfp;
 float worstvmin,worstfp,worstsnm;
 tmpvmin=tmpsnm=tmpfp=0;
 worstvmin=vddmin[0];worstfp=fpblocks[0];worstsnm=snmmin[0];
 int disableblks=0;
 for (int i=0; i < numblks; i++) {
	tmpvmin += vddmin[i];
	tmpsnm += snmmin[i];
	tmpfp += fpblocks[i];
	if (vddmin[i]>= worstvmin)
	  worstvmin=vddmin[i];
	if (fpblocks[i]>= worstfp)
	  worstfp = fpblocks[i];
	if (snmmin[i] <= worstsnm)
	  worstsnm= snmmin[i];
	if ((((vdd-vddmin2[i])/vdd)*100)<= 20) {
	  disableblks++;
	  printf(" (((vdd-vddmin2[i])/vdd)*100) is %f",(((vdd-vddmin2[i])/vdd)*100));
	}
 }
 avgvmin = tmpvmin/numblks;
 avgsnm = tmpsnm/numblks;
 avgfp = tmpfp/numblks;

 printf("\t\t\t***************************************************\n\t\t\t***\t\t\t\t\t\t***\n\t\t\t***\t\tCache Configuration\t\t***\n\t\t\t*** Cache size is %d Kilo Bytes\t\t\t***\n\t\t\t*** Block size is %d Bytes\t\t\t***\n\t\t\t*** Number of blks is %d \t\t\t***\n\t\t\t***\t\t\t\t\t\t***\n\t\t\t***************************************************\n\n",cachesize/(8*1024),blksize/8,numblks);
 printf("Worst case Vdd min is %f and Average Vdd min is %f\nWorst case snm min is %f and Average snm min is %f\nWorst case failure probability is %f and Average failure probability is %f\n",worstvmin,avgvmin,worstsnm,avgsnm,worstfp,avgfp);
 printf("Outof %d blocks %d blocks are disabled for error free operation\n",numblks,disableblks);
 float yld = (float)(disableblks*blksize)/cachesize;
 printf("blksize=%d, cachesize=%d and Yield reduction is: %f\n",blksize,cachesize,yld);
 /*for (int i=0; i < numblks; i++) {
     //failingsum += (snmmin[i] <= vmin) ? 1 : 0;
 	printf("block[%d] vddmin is %f minimum safe vdd is %f worst snm is  %f and failure probability is %f\n",i, vddmin2[i], vddmin[i],snmmin[i], fpblocks[i]);
 }*/
//float failP = (float)failingsum/(bsize*10);
//printf("failure probability = %f\n",failP);
/* this is a trial for git version control system
done on purpose*/
 return 0;
}
