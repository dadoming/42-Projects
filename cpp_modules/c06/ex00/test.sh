YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}Test 0${NC}"
./Convert 0
echo -e "\n${YELLOW}Test nan${NC}"
./Convert nan
echo -e "\n${YELLOW}Test 42.0f${NC}"
./Convert 42.0f
echo -e "\n${YELLOW}Test 42.0${NC}"
./Convert 42.0
echo -e "\n${YELLOW}Test 42${NC}"
./Convert 42
echo -e "\n${YELLOW}Test nanf${NC}"
./Convert nanf
echo -e "\n${YELLOW}Test +inff${NC}"
./Convert +inff
echo -e "\n${YELLOW}Test -inff${NC}"
./Convert -inff
echo -e "\n${YELLOW}Test +inf${NC}"
./Convert +inf
echo -e "\n${YELLOW}Test -inf${NC}"
./Convert -inf
echo -e "\n${YELLOW}Test 2147483646${NC}"
./Convert 2147483646
echo -e "\n${YELLOW}Test 2147483647${NC}"
./Convert 2147483647
echo -e "\n${YELLOW}Test -2147483648${NC}"
./Convert -2147483648
echo -e "\n${YELLOW}Test 2147483648${NC}"
./Convert 2147483648
echo -e "\n${YELLOW}Test -2147483649${NC}"
./Convert -2147483649
echo -e "\n${YELLOW}Test 9223372036854775807${NC}"
./Convert 9223372036854775807
