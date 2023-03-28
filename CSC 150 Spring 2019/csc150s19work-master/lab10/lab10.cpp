#include <iostream>
#include <iomanip>

using namespace std;

bool example_test_toupper();
bool example_left_rotate_char();
bool student_right_rotate_char();
bool example_left_rotate_message();
bool example_right_rotate_message();
bool example_unencrypt();

char rotate_char(const char input, int places);
void rotate_message(const char input[], char output[], int places);

/** ****************************************************************************
 * @brief The main entry point for the program.
 *
 * @details Prompts the user for a message, and an amount to rotate the message.
 * The program then rotates the given message and prints it to the screen.
 *
 * @param argc The number of commandline arguments.
 * @param argv An array of commandline arguments.
 *
 * @returns 0 if the program was successful, 1 otherwise.
 ******************************************************************************/
int main()
{

    // test harness stop
    int rotate_value = 0;
    char output[1024] = { 0 };
    char message[1024] = { 0 };
    if (example_test_toupper()
        || example_left_rotate_char()
        || student_right_rotate_char()
        || example_left_rotate_message()
        || example_right_rotate_message()
        || example_unencrypt())
    {
        cout << "some of your functions are not passing the test harness."
            << endl;
        return 1;
    }


    cout << "Enter your message: ";
    cin.getline(message, 1024);

    cout << "Amount to rotate: ";
    cin >> rotate_value;
    rotate_message(message, output, rotate_value);
    cout << output << endl;

    return 0;
}

/** ****************************************************************************
 * @brief Rotates the given character by the given number of places
 *
 * @param input   The character to rotate.
 * @param places  The number of places to rotate the character. Negative values
 *                will rotate the character to the left, and positive values
 *                will rotate the character to the right.
 *
 * @returns The rotated character.
 ******************************************************************************/
char rotate_char(const char input, int places)
{
    int index = input - 'A';
    index += places;
    index += 26;
    index = index % 26;
    return index + 'A';
}

/** ****************************************************************************
 * @brief Rotates the given message by the provided number of places.
 *
 * @param[in]  input   The message to rotate.
 * @param[out] output  The output buffer to store the rotated message in.
 * @param[in]  places  The number of places to rotate each character of the
 *                     message. Negative values will rotate to the left, and
 *                     positive values will rotate to the right.
 ******************************************************************************/
void rotate_message(const char input[], char output[], int places)
{
    int i = 0;
    while (input[i] != '\0')
    {
        if (isalpha(input[i]))
        {
            output[i] = rotate_char(toupper(input[i]), places);
        }
        else
        {
            output[i] = input[i];
        }

        i++;
    }
    output[i] = '\0';
}

bool example_test_toupper()
{
    char input1 = 'a';
    char expected1 = 'A';
    char input2 = 'A';
    char expected2 = 'A';
    char input3 = '!';
    char expected3 = '!';

    if (!(toupper(input1) == expected1))
    {
        cout << "toupper: failed 'a' case" << endl;
        return true;
    }

    if (!(toupper(input2) == expected2))
    {
        cout << "toupper: failed 'A' case" << endl;
        return true;
    }

    if (!(toupper(input3) == expected3))
    {
        cout << "toupper: failed '!' case" << endl;
        return true;
    }

    return false;
}

bool example_left_rotate_char()
{
    if (!(rotate_char('A', -3) == 'X'))
    {
        cout << "left rotate_char: failed 'A -3' case" << endl;
        return true;
    }

    if (!(rotate_char('B', -2) == 'Z'))
    {
        cout << "left rotate_char: failed 'B -2' case" << endl;
        return true;
    }

    if (!(rotate_char('Z', -3) == 'W'))
    {
        cout << "left rotate_char: failed 'Z -3' case" << endl;
        return true;
    }

    if (!(rotate_char('A', -2) == 'Y'))
    {
        cout << "left rotate_char: failed 'A -2' case" << endl;
        return true;
    }
    return false;
}

bool student_right_rotate_char()
{
    // Add two IF test statements:
    if (!(rotate_char('A', 4) == 'E'))
    {
        cout << "left rotate_char: failed 'A +3' case" << endl;
        return true;
    }

    if (!(rotate_char('B', 2) == 'D'))
    {
        cout << "left rotate_char: failed 'B +2' case" << endl;
        return true;
    }

    if (!(rotate_char('Z', 3) == 'C'))
    {
        cout << "left rotate_char: failed 'Z +3' case" << endl;
        return true;
    }

    if (!(rotate_char('A', 2) == 'C'))
    {
        cout << "left rotate_char: failed 'A +2' case" << endl;
        return true;
    }
    return false;
}

bool example_left_rotate_message()
{
    // two test cases
    char ciphertext[100] = "";
    char message1[100] = "I really hate null-terminated strings!";
    char expected1[100] = "V ERNYYL UNGR AHYY-GREZVANGRQ FGEVATF!";
    rotate_message(message1, ciphertext, -13);
    if (!(strcmp(ciphertext, expected1) == 0))
    {
        cout << "left rotate_message: failed '" << message1 << "'case" << endl;
        return true;
    }

    char message2[100] = "Why can't everything just be easy?!";
    char expected2[100] = "VGX BZM'S DUDQXSGHMF ITRS AD DZRX?!";
    rotate_message(message2, ciphertext, -1);
    if (!(strcmp(ciphertext, expected2) == 0))
    {
        cout << "left rotate_message: failed '" << message2 << "'case" << endl;
        return true;
    }
    return false;
}

bool example_right_rotate_message()
{
    // two test cases
    char ciphertext[100] = "";

    char message1[100] = "Isn't cryptography so fun?!";
    char expected1[100] = "MWR'X GVCTXSKVETLC WS JYR?!";
    rotate_message(message1, ciphertext, 4);
    if (!(strcmp(ciphertext, expected1) == 0))
    {
        cout << "right rotate_message: failed '" << message1 << "'case" << endl;
        return true;
    }

    char message2[100] = "No, I really don't think it is...";
    char expected2[100] = "CD, X GTPAAN SDC'I IWXCZ XI XH...";
    rotate_message(message2, ciphertext, 15);
    if (!(strcmp(ciphertext, expected2) == 0))
    {
        cout << "rotate rotate_message: failed '" << message2 << "'case" << endl;
        return true;
    }
    return false;
}

bool example_unencrypt()
{
    // Note that this only works if the original text is all uppercase!
    char original_plaintext[100] = "AI";
    char ciphertext[100] = "";
    char plaintext[100] = "";

    // Encrypt the message with a left rotation and store the result.
    rotate_message(original_plaintext, ciphertext, -3);
    // Decrypt the message with a right rotation and store the result.
    rotate_message(ciphertext, plaintext, 3);

    // Make sure what we got back was what we had when we started.
    if (!(strcmp(plaintext, original_plaintext) == 0))
    {
        cout << " D(E(p)) = p: failed '" << original_plaintext << "'case" << endl;
        return true;
    }

    //! @note This will be a sticking point, the decrypted message will be all caps.
    char message[100] = "THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.";

    rotate_message(message, ciphertext, -5);
    rotate_message(ciphertext, plaintext, 5);
    if (!(strcmp(plaintext, message) == 0))
    {
        cout << " D(E(p)) = p: failed '" << message << "'case" << endl;
        return true;
    }
    return false;
}


