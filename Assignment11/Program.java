// @author Sahil Naphade Roll no. 43141
// R-9
//	Import weka classes
import weka.core.Instances;
import weka.classifiers.Evaluation;
import weka.classifiers.bayes.NaiveBayes;
import weka.classifiers.evaluation.ConfusionMatrix;

// 	Import required JAVA classes
import java.io.BufferedReader;
//import java.io.FileNotFoundException;
import java.io.FileReader;
import java.lang.Exception;

public class Program {
	public static void main(String[] args) throws Exception{
		BufferedReader trReader = new BufferedReader(new FileReader("../Datasets/training.arff"));
		BufferedReader tsReader = new BufferedReader(new FileReader("../Datasets/testing.arff"));

		Instances training = new Instances(trReader);
		Instances testing = new Instances(tsReader);

		trReader.close();
		tsReader.close();

		training.setClassIndex(training.numAttributes() - 1);
		testing.setClassIndex(testing.numAttributes() - 1);

		NaiveBayes nb = new NaiveBayes();
		nb.buildClassifier(training);
		System.out.println(nb);

		Evaluation eval = new Evaluation(testing);
		eval.evaluateModel(nb, testing);
		System.out.println(eval.toSummaryString("\nResults testing\n", true));

		for(int i = 0; i < training.numClasses(); i++) {
			System.out.println("Class "+ i);
			System.out.println(eval.precision(i) + " " + eval.recall(i) + " " + eval.areaUnderROC(i));
		}
	}
}
