#include "MyForm.h"
#include "equation.h"

System::Void winformyMertvi::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	double a, b, c, x1, x2, root1, root2;
	try {
		if (!Double::TryParse(textBox1->Text, a)) {
			throw gcnew System::FormatException("���������� �������� 'a'.");
		}

		if (a < -999999 || a > 999999) {
			throw gcnew System::Exception("�������� 'a' �� ����������� ������ [-999999; 999999].");
		}

		if (!Double::TryParse(textBox2->Text, b)) {
			throw gcnew System::FormatException("���������� �������� 'b'.");
		}

		if (b < -999999 || b > 999999) {
			throw gcnew System::Exception("�������� 'b' �� ����������� ������ [-999999; 999999].");
		}

		if (!Double::TryParse(textBox3->Text, c)) {
			throw gcnew System::FormatException("���������� �������� 'c'.");
		}

		if (c < -999999 || c > 999999) {
			throw gcnew System::Exception("�������� 'c' �� ����������� ������ [-999999; 999999].");
		}

		if (!Double::TryParse(textBox5->Text, x1)) {
			throw gcnew System::FormatException("���������� �������� 'x1'.");
		}

		if (x1 < -999999 || x1 > 999999) {
			throw gcnew System::Exception("�������� 'x1' �� ����������� ������ [-999999; 999999].");
		}

		if (!Double::TryParse(textBox4->Text, x2)) {
			throw gcnew System::FormatException("���������� �������� 'x2'.");
		}

		if (x2 < -999999 || x2 > 999999) {
			throw gcnew System::Exception("�������� 'x2' �� ����������� ������ [-999999; 999999].");
		}

		if (a == 0) {
			throw gcnew System::Exception("г������ �� � ����������, ������� a = 0.");
		}

		if (x1 > x2) {
			throw gcnew System::Exception("��������� ���. x1 ������� ���� ����� �� x2.");
		}

		Equation equation(a, b, c);
		equation.calculate();

		root1 = equation.getRoot1();
		root2 = equation.getRoot2();

		std::stringstream ss;

		ss << a;

		std::string input_equation = "������� �������: " + ss.str() + "*x^2";

		ss.str("");

		if (b < 0) {
			ss << -b;
			input_equation += " - " + ss.str() + "*x";
			ss.str("");
		}
		else if (b > 0) {
			ss << b;
			input_equation += " + " + ss.str() + "*x";
			ss.str("");
		}
		if (c < 0) {
			ss << -c;
			input_equation += " - " + ss.str();
			ss.str("");
		}
		else if (c > 0) {
			ss << c;
			input_equation += " + " + ss.str();
			ss.str("");
		}
		input_equation += " = 0";

		System::String^ equationText = msclr::interop::marshal_as<System::String^>(input_equation);
		label9->Text = equationText;

		std::string input_range = "������ ���: ";

		if (x1 == x2) {
			ss << x1;
			input_range += "{" + ss.str() + "}";
			ss.str("");
		}
		else {
			ss << x1;
			input_range += "[" + ss.str() + "; ";
			ss.str("");
			ss << x2;
			input_range += ss.str() + "]";
			ss.str("");
		}

		System::String^ rangeText = msclr::interop::marshal_as<System::String^>(input_range);
		label10->Text = rangeText;

		std::string output_root;
		std::string output_range;

		if (std::isnan(root1) || std::isnan(root2)) {
			output_root = "г������ �� �� ������ ������";
			output_range = "";
		}
		else if (root1 == root2) {
			ss << root1;
			output_root = "����� �������: " + ss.str();
			ss.str("");
			if (x1 <= root1 && root1 <= x2) {
				output_range += "����� �������� ������� " + input_range.erase(0, 14) + "\n";
			}
			else {
				output_range += "����� �� �������� ������� " + input_range.erase(0, 14) + "\n";
			}
		}
		else {
			ss << root1;
			output_root = "����� 1: " + ss.str() + "\n";
			ss.str("");
			ss << root2;
			output_root += "����� 2: " + ss.str();
			ss.str("");

			if (x1 <= root1 && root1 <= x2) {
				output_range += "����� 1 �������� ������� " + input_range.erase(0, 14) + "\n";
			}
			else {
				output_range += "����� 1 �� �������� ������� " + input_range.erase(0, 14) + "\n";
			}
			if (x1 <= root2 && root2 <= x2) {
				output_range += "����� 2 �������� ������� " + input_range;
			}
			else {
				output_range += "����� 2 �� �������� ������� " + input_range;
			}
		}

		System::String^ rootText = msclr::interop::marshal_as<System::String^>(output_root);
		label11->Text = rootText;

		System::String^ conclusionText = msclr::interop::marshal_as<System::String^>(output_range);
		label13->Text = conclusionText;
	}
	catch (System::FormatException^ ex) {
		MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}