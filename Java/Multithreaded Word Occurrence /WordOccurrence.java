import java.io.*;
import java.util.*;

/*
    To run the program:
    1. You need to enter a folder name for example => Demo
    2. Then enter a word of your choice 
    Using multithreading, the program should show you how many times this word occurred in that folder
 */

public class WordOccurrence {

    public static void main(String args[]) {

        String s = null, DirectoryPath = null;

        try (Scanner input = new Scanner(System.in)) {
            System.out.println("Enter a folder name: ");
            DirectoryPath = input.nextLine();
            System.out.println("Enter a word: ");
            s = input.nextLine();
        }
        File directoryPath = new File(DirectoryPath);

        File arr[] = directoryPath.listFiles();
        List<String> files = new ArrayList<>();

        GetAllFiles(arr, files, 0, 0);

        List<Map<String, Integer>> wordCounts = new ArrayList<Map<String, Integer>>();

        // Build thread list
        ArrayList<ThreadsProcessingFiles> threadlist = new ArrayList<ThreadsProcessingFiles>();
        for (int i = 0; i < arr.length; i++) {
            if (!arr[i].toString().contains(".DS_Store")) {
                // ! the if statement is just to skip the .ds_store file which
                // ! contains the folder settings and can't be accessed
                ThreadsProcessingFiles t = new ThreadsProcessingFiles(files.get(i));
                threadlist.add(t);
                t.start();
            }
        }

        for (ThreadsProcessingFiles t : threadlist) {
            try {
                t.join();
                wordCounts.add(t.getWordCount());
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }

        // Merge all maps from each thread (find words count from all files)
        Map<String, Integer> totalWCount = new HashMap<String, Integer>();
        for (Map<String, Integer> wcount : wordCounts) {
            for (Map.Entry<String, Integer> entry : wcount.entrySet()) {
                String iword = entry.getKey();
                Integer icount = entry.getValue();
                Integer count = totalWCount.get(iword);
                totalWCount.put(iword, count == null ? icount : count + icount);
            }
        }

        for (Map.Entry<String, Integer> entry : totalWCount.entrySet()) {
            if (entry.getKey().equalsIgnoreCase(s))
                System.out.println("The word (" + entry.getKey() + ") appeared " + entry.getValue() + " time/s.\n");
        }
    }

    public static void GetAllFiles(File[] arr, List<String> files, int index, int level) { // Traverse the files tree
                                                                                           // and store each file into
                                                                                           // the list recursively
        if (index == arr.length)
            return;
        if (arr[index].isFile()) {
            files.add(arr[index].toString());
        } else if (arr[index].isDirectory()) {

            // recursion for sub-directories
            GetAllFiles(arr[index].listFiles(), files, 0,
                    level + 1);
        }

        // recursion for main directory
        GetAllFiles(arr, files, ++index, level);
    }

}

class ThreadsProcessingFiles extends Thread {
    private String _filename;
    private Map<String, Integer> _wordCount;
    public static String[] words;

    public ThreadsProcessingFiles(String Fname) {
        this._filename = Fname;
        this._wordCount = new HashMap<String, Integer>();
    }

    public Map<String, Integer> getWordCount() {
        return this._wordCount;
    }

    @Override
    public void run() {
        try (Scanner scanner = new Scanner(new File(_filename))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                words = line.split(" ");

                // here so it can use the split from the previous line
                for (String word : words) {
                    word = word.toLowerCase();
                    if (!_wordCount.containsKey(word)) {
                        _wordCount.put(word, 1);
                    } else {
                        _wordCount.put(word, _wordCount.get(word) + 1);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}