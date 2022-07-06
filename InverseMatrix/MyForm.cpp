#include "MyForm.h"
#include "Class.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MatForms::MyForm form;
    Application::Run(% form);
}

int size;
Matrix M1;
Matrix L;
Matrix U;
Matrix P;
Matrix C;
Matrix X;

System::Void MatForms::MyForm::buttonGenA_Click(System::Object^ sender, System::EventArgs^ e) 
{
    // Converting the size from the numeric updown value to integer
    size = Convert::ToInt32(numericUpDown1->Value);
    // Creating matrix and filling it with random numbers
    M1.SetSize(size);
    M1.Random();

    dataGridView1->RowCount = size;
    dataGridView1->ColumnCount = size;

    // Showing the Matrix
    ShowA();

    dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView1->AutoResizeColumns();
    return System::Void();
}

System::Void MatForms::MyForm::buttonCreateA_Click(System::Object^ sender, System::EventArgs^ e)
{
    size = Convert::ToInt32(numericUpDown1->Value);
    M1.SetSize(size);

    dataGridView1->RowCount = size;
    dataGridView1->ColumnCount = size;

    ShowA();

    dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView1->AutoResizeColumns();
    return System::Void();
}

System::Void MatForms::MyForm::buttonGauss_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (size == 0)
    {
        MessageBox::Show("Looks like you didn't create a matrix!","Damn");
        return;
    }
    if (determinant(M1, size) == 0)
    {
        MessageBox::Show("The determinant is equal to zero!", "Error");
    }
    dataGridViewRes->RowCount = size;
    dataGridViewRes->ColumnCount = size;

    // Finding the inverse matrix with Gauss method
    Gauss(M1);
    // Showing the resulting matrix
    ShowB();
    File(M1);

    dataGridViewRes->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridViewRes->AutoResizeColumns();
    return System::Void();
}

System::Void MatForms::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Error message
    if (size == 0)
    {
        MessageBox::Show("Looks like you didn't create a matrix!", "Damn");
        return;
    }
    dataGridViewRes->RowCount = size;
    dataGridViewRes->ColumnCount = size;
    dataGridView2->RowCount = size;
    dataGridView2->ColumnCount = size;
    dataGridView4->RowCount = size;
    dataGridView4->ColumnCount = size;

    label5->Text = "L";
    label7->Text = "U";
    L.SetSize(size);
    U.SetSize(size);
    if (determinant(M1, size) == 0)
    {
        MessageBox::Show("The determinant is equal to zero!", "Error");
    }
    // Finding the LU-decomposition of the matrix
    LUdecomposition(M1, L, U, size);
    // Showing L- and U- decomposition matrices
    ShowL();
    ShowU();
    // Inversing L- and U- decomposition matrices
    Gauss(U);
    Gauss(L);
    // Finding the inverse matrix with LU-decomposition method
    M1 = U * L;
    // Showing the resulting matrix
    ShowB();
    File(M1);

    dataGridViewRes->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridViewRes->AutoResizeColumns();
    dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView2->AutoResizeColumns();
    dataGridView4->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView4->AutoResizeColumns();
    return System::Void();
}

System::Void MatForms::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (size == 0)
    {
        MessageBox::Show("Looks like you didn't create a matrix!", "Damn");
        return;
    }
    dataGridViewRes->RowCount = size;
    dataGridViewRes->ColumnCount = size;
    dataGridView2->RowCount = size;
    dataGridView2->ColumnCount = size;
    dataGridView4->RowCount = size;
    dataGridView4->ColumnCount = size;
    dataGridView3->RowCount = size;
    dataGridView3->ColumnCount = size;
    dataGridView5->RowCount = size;
    dataGridView5->ColumnCount = size;

    if (determinant(M1, size) == 0)
    {
        MessageBox::Show("The determinant is equal to zero!","Error");
    }

    label5->Text = "L";
    label7->Text = "U";
    label8->Text = "C";
    label6->Text = "P";
    L.SetSize(size);
    U.SetSize(size);
    C.SetSize(size);
    P.SetSize(size);
    LUP(M1, P);
    ShowC();
    LUdecomposition(M1, L, U, size);
    ShowL();
    ShowU();
    Gauss(L);
    Gauss(U);
    ShowP();
    M1 = U * L;
    M1 = M1 * P;
    // Showing the resulting matrix
    ShowB();
    File(M1);

    dataGridViewRes->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridViewRes->AutoResizeColumns();
    dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView2->AutoResizeColumns();
    dataGridView4->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView4->AutoResizeColumns();
    dataGridView3->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView3->AutoResizeColumns();
    dataGridView5->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView5->AutoResizeColumns();
    return System::Void();
}

System::Void MatForms::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Saving the changes that user made
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            M1.SetElement(i, j, Convert::ToDouble(dataGridView1->Rows[i]->Cells[j]->Value));
        }
    }
    return System::Void();
}

System::Void MatForms::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Importing the matrix from file
    std::fstream f;
    f.open("Import.txt");
    size = Convert::ToInt32(numericUpDown1->Value);
    double** arr = new double* [size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new double[size]{};
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            f >> arr[i][j];
            M1.SetElement(i, j, arr[i][j]);
        }
    }
    f.close();
    ShowA();
    return System::Void();
}

System::Void MatForms::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Saving the matrix to file
    int size = M1.GetSize();
    std::ofstream fout;
    fout.open("Matrix.txt");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fout << M1.GetElement(i, j) << " ";
        }
        fout << "\n";
    }
    fout.close();
    return System::Void();
}

void MatForms::MyForm::ShowA()
{
    // Showing the matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dataGridView1->TopLeftHeaderCell->Value = "Matrix 1";
            dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
            dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
            dataGridView1->Rows[i]->Cells[j]->Value = M1.GetElement(i, j);
        }
    }
}

void MatForms::MyForm::ShowB()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dataGridViewRes->TopLeftHeaderCell->Value = "Matrix 2";
            dataGridViewRes->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
            dataGridViewRes->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
            dataGridViewRes->Rows[i]->Cells[j]->Value = M1.GetElement(i, j);
        }
    }
}

void MatForms::MyForm::ShowL()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dataGridView2->TopLeftHeaderCell->Value = "Matrix L";
            dataGridView2->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
            dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
            dataGridView2->Rows[i]->Cells[j]->Value = L.GetElement(i, j);

        }
    }
}

void MatForms::MyForm::ShowU()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dataGridView4->TopLeftHeaderCell->Value = "Matrix U";
            dataGridView4->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
            dataGridView4->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
            dataGridView4->Rows[i]->Cells[j]->Value = U.GetElement(i, j);
        }
    }
}

void MatForms::MyForm::ShowP()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dataGridView3->TopLeftHeaderCell->Value = "Matrix P";
            dataGridView3->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
            dataGridView3->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
            dataGridView3->Rows[i]->Cells[j]->Value = P.GetElement(i, j);
        }
    }
}

void MatForms::MyForm::ShowC()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dataGridView5->TopLeftHeaderCell->Value = "Matrix C";
            dataGridView5->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
            dataGridView5->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
            dataGridView5->Rows[i]->Cells[j]->Value = M1.GetElement(i, j);
        }
    }
}