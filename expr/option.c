#include <getopt.h>
#include <stdio.h>
#include <string.h>

#define size 256

void usage(FILE *fp, const char *path) {
  const char *basename = strchr(path, '/');
  basename = basename ? basename + 1 : path;

  fprintf(fp, "usage: %s [OPTION]\n", basename);
  fprintf(fp, " -h, --help\t\t"
              "print this help and exit\n");
  fprintf(fp, " -f, --file[=FILENAME]\t"
              "Write all output to a file (defaults to out.txt).\n");
  fprintf(fp, " -m, --message=STRING\t"
              "Output a particular message rather than 'hello world'.\n");
}

int main(int argc, char **argv) {
  char filename[size] = {0};
  char message[size] = {0};
  FILE *fp;
  int help_flag = 0;
  int opt;
  struct option longopts[] = {{"help", no_argument, &help_flag, 1},
                              {"file", optional_argument, NULL, 'f'},
                              {"msg", required_argument, NULL, 'm'},
                              {0}};

  while (1) {
    opt = getopt_long(argc, argv, "hf::m:", longopts, 0);
    if (opt == -1) {
      break;
    }

    switch (opt) {
    case 'h':
      help_flag = 1;
      break;
    case 'f':
      printf("outarg: '%s'\n", optarg);
      strncpy(filename, optarg ? optarg : "out.txt", sizeof(filename));
      filename[sizeof(filename) - 1] = '\0';
      break;
    case 'm':
      strncpy(message, optarg, sizeof(message));
      message[sizeof(message) - 1] = '\0';
      break;
    case '?':
      usage(stderr, argv[0]);
      return 1;
    default:
      break;
    }
  }

  if (help_flag) {
    usage(stdout, argv[0]);
    return 0;
  }
  if (filename[0]) {
    fp = fopen(filename, "w");
  } else {
    fp = stdout;
  }
  if (!fp) {
    fprintf(stderr, "Failed to open file.\n");
    return 1;
  }
  fprintf(fp, "%s\n", message);
  fclose(fp);
  return 0;
}