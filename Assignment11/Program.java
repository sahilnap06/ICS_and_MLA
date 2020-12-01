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
			//Read the training dataset (70%)
			BufferedReader trainReader = new BufferedReader(new FileReader("E:/College/CL7/Assignment11/Diabetes_train.arff"));
			//Read the testing dataset (30%)
			BufferedReader testReader = new BufferedReader(new FileReader("E:/College/CL7/Assignment11/Diabetes_test.arff"));
			Instances trainInstns = new Instances(trainReader);
			Instances testInstns = new Instances(testReader);

			trainReader.close();
			testReader.close();

			trainInstns.setClassIndex(trainInstns.numAttributes() - 1);
			testInstns.setClassIndex(testInstns.numAttributes() - 1);

			NaiveBayes NBModel = new NaiveBayes();
			NBModel.buildClassifier(trainInstns);
			System.out.println(NBModel);
			Evaluation etest = new Evaluation(testInstns);
			etest.evaluateModel(NBModel, testInstns);
			String[] cmarray = {"Non-diabetic", "Diabetic"};

			ConfusionMatrix cm = new ConfusionMatrix(cmarray);
			System.out.println(cm.correct());

			for(int i = 0; i < testInstns.numInstances(); i++) {
				testInstns.instance(i).setClassMissing();
				double cls = NBModel.classifyInstance(testInstns.instance(i));
				testInstns.instance(i).setClassValue(cls);
			}

			System.out.println("Error rate =  " + etest.errorRate()*100);
			System.out.println("Pct correct: " + etest.pctCorrect());

			for(int i = 0; i < trainInstns.numClasses(); i++) {
				System.out.println("Class: " + i);
				System.out.println("Precision: " + etest.precision(i));
				System.out.println("Recall: " + etest.recall(i));
				System.out.println("Area under ROC: " + etest.areaUnderROC(i));
				System.out.println("------------------------------------");
			}
	}
}
