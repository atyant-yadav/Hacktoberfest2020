package calc;

import org.apache.commons.lang3.StringUtils;

import java.util.ArrayList;
import java.util.List;


public class StringCalculator {

    public static int add(String input) {
        InnerStringCalculator calculator = new InnerStringCalculator(input);
        return calculator.add();
    }

    static class InnerStringCalculator {
        private final String input;

        private String delimiter = "[,\n]";
        private String numbersWithDelimiters;
        private List<String> negativeTokens = new ArrayList<String>();

        private InnerStringCalculator(String input) {
            this.input = input;
        }

        public int add() {
            if (isInputEmpty()) {
                return 0;
            }
            parseDelimiterAndFindLineWithNumbersAndDelimiters();
            String[] inputSplittedByDelimiter = splitInputByDelimiter();
            return calculateSum(inputSplittedByDelimiter);
        }

        private boolean isInputEmpty() {
        	if(null==input)
        		return true;
            return input.length() == 0;
        }

        private void parseDelimiterAndFindLineWithNumbersAndDelimiters() {
            if (hasCustomDelimiter()) {
                parseDelimiter();
                findLineWithNumbersAndDelimiters();
            } else {
                numbersWithDelimiters = input;
            }
        }

        private boolean hasCustomDelimiter() {
            return input.startsWith("//");
        }


        private void findLineWithNumbersAndDelimiters() {
            int firstNewLine = input.indexOf("\n");
            numbersWithDelimiters = input.substring(firstNewLine + 1);
        }

        private void parseDelimiter() {
            delimiter = "";
            addDelimiters();
            delimiter = StringUtils.chop(delimiter);
        }

        private void addDelimiters() {
            int startIndexDelimiter = 0;
            while (true) {
                startIndexDelimiter = input.indexOf("[", startIndexDelimiter) + 1;
                if (startIndexDelimiter == 0) {
                    break;
                }
                int endIndexDelimiter = input.indexOf("]", startIndexDelimiter);
                delimiter += input.substring(startIndexDelimiter, endIndexDelimiter) + "|";
            }
        }

        private String[] splitInputByDelimiter() {
            return numbersWithDelimiters.split(delimiter);
        }

        private int calculateSum(String[] inputSplittedByDelimiter) {
            int result = 0;
            for (String token : inputSplittedByDelimiter) {
                result += addSingleToken(token);
            }
            throwExceptionIfNegativeTokensExist();
            return result;
        }

        private void throwExceptionIfNegativeTokensExist() {
            if (hasNegativeTokens()) {
                throw new IllegalArgumentException(String.format("negatives not allowed (%s)", StringUtils.join(negativeTokens, ",")));
            }
        }

        private boolean hasNegativeTokens() {
            return negativeTokens.size() > 0;
        }

        private int addSingleToken(String token) {
            Integer valueAsInteger = Integer.parseInt(token);
            if (isNegative(valueAsInteger)) {
                negativeTokens.add(token);
            } else if (isInValidRange(valueAsInteger)) {
                return valueAsInteger;
            }
            return 0;
        }

        private boolean isNegative(Integer valueAsInteger) {
            return valueAsInteger < 0;
        }

        private boolean isInValidRange(Integer valueAsInteger) {
            return valueAsInteger < 100;
        }
    }
}