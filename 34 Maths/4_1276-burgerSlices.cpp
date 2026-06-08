// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/

vector<int> numOfBurgers(int t, int c)
{
    if (t % 2 != 0)
        return {};

    int x = (t / 2) - c;
    int y = (2 * c) - (t / 2);

    if (x < 0 || y < 0)
        return {};

    return vector<int>{x, y};
}