#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <netinet/in.h>  /* for IPPROTO_TCP / IPPROTO_UDP */
#include <ctype.h>
#include <sys/time.h>				/* */
#include <arpa/inet.h>				/* For inet_aton            */
#include <assert.h>				/* */
#include <stdbool.h>				/* Need for the bool type   */
#include <unistd.h>       /*for sleep function*/


#include "DM_ENG_RPCInterface.h"  		/* DM_Engine module definition    */
#include "DM_GlobalDefs.h"			/* */
#include "DM_ENG_Parameter.h"			/* */
#include "DM_ENG_ParameterData.h"
#include "DM_ENG_Common.h"			/* */
#include "dm_com_utils.h"			/* */
#include "DM_COM_ConnectionSecurity.h"		/* */
#include "CMN_Trace.h"

int main(int argc, char const *argv[]) {
  char* datapath = "./rsc";
  bool factoryReset = true;
  int res = DM_ENG_ParameterData_init(datapath, factoryReset);
  if (res == 0) {printf("%s\n", "init success!!!");}
  DM_ENG_Parameter* newParam = malloc(sizeof(DM_ENG_Parameter));
  newParam = DM_ENG_ParameterData_getFirst();
  /*char node[strlen(newParam->name)+1];
  memset(node, '\0', sizeof(node));
  strcpy(node, newParam->name);
  printf("%s\n", node);*/
  printf("%s\n", newParam->name);
  int i ;
  for (i = 0; i < 15; i++){
    char* name = DM_ENG_ParameterData_getNextName();
    printf("%s\n", name);
  }
  free(newParam);
  return 0;
}
