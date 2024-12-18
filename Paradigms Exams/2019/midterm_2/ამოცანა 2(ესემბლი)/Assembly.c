struct cpu{
    int id;
    short core[2];
};

struct serverRoom{
    char* model;
    struct cpu node;
    struct cpu* next;
};

typedef char* (*bootstrapScript)(struct cpu*);

bootstrapScript GetSetupScript(char* model);
struct cpu** SetupServers(struct cpu* server, bootstrapScript script);

//ეს მეთოდია დასაწერი
struct cpu** CreateComputerLab(short* roomNumber, struct serverRoom* servers){
    roomNumber[*roomNumber] = 0;
    if(servers[2].node.id > 3)
        servers += ((struct cpu*)(servers->next[0].cores))->id;
    bootstrapScript localScript = GetSetupScript(servers[0].model);
    return SetupServers((struct cpu*)&servers, localScript);
}