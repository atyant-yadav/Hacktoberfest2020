using System;
using System.Collections.Generic;
using MySql.Data.MySqlClient;

namespace SqlController
{
    class APImysql
    {
        // !!CONFIG!!
        private const string SERVER = "localhost";
        private const string PORT = "3306";
        private const string DATABASE = "db2079";
        private const string USER = "root";
        private const string PASSWORD = "";
        //Implements
        private static string connectionString = "Server=" + SERVER + ";Port=" + PORT + ";Database=" + DATABASE + ";Uid=" + USER + ";Password=" + PASSWORD;





        // !!In this method you can config how your DB-data should be written to your list!!
        private string readHandling(MySqlDataReader pDataReader, int pIndex)
        {
            //Usually if you convert a type DATE into string, the time gets added to. Here we don't want that.
            if (pDataReader.GetDataTypeName(pIndex) == "DATE")
            {
                try
                {
                    DateTime dateOutput = new DateTime();
                    dateOutput = pDataReader.GetDateTime(pIndex);

                    //********************* An example what you can do: *********************

                    //For an unknown date I like to save it as 01.01.1000: Here I convert the value back to "unknown"
                    //I'm from Europe so we use the calender in this format: :D
                    if (dateOutput.ToString("dd/MM/yyyy") == "01.01.1000")
                    {
                        return "unknown";
                    }
                    else
                    {
                        return dateOutput.ToString("dd/MM/yyyy");
                    }

                    //********************* delete upper section if you don't wanna have it *********************
                    //than uncomment this: 
                    //return dateOutput.ToString("dd/MM/yyyy");
                }
                catch
                {
                    return "FAILURE: readerHandling! DATE";
                }

            }
            else if (false)
            {
                //If you wanna have another special read handling
            }
            else
            {
                return pDataReader.GetString(pIndex);
            }
        }






        //-----Dataflow
        public List<string> select(string pQuery, int pNumberColumns)
        {
            Console.WriteLine(pQuery);
            //NumberColumns -> Index
            pNumberColumns -= 1;
            //Do not crash when there is no connection
            try
            {
                //new list for output
                List<string> requestedData = new List<string>();
                //Open connection
                MySqlConnection sqlConnection = new MySqlConnection(connectionString);
                MySqlCommand sqlCommand = new MySqlCommand(pQuery, sqlConnection);
                sqlConnection.Open();
                //Reader class
                MySqlDataReader dataReader;
                dataReader = sqlCommand.ExecuteReader();
                //write data in list
                while (dataReader.Read()) //to read all data
                {
                    for (int i = 0; i <= pNumberColumns; i++) //So that one row is save as one record
                    {
                        //How your data should be saved
                        requestedData.Add(readHandling(dataReader, i));

                    }

                }
                sqlConnection.Close(); //Close connection
                return requestedData; //pass list
            }
            catch
            {
                //error message when no connection
                List<string> error = new List<string>();
                Console.WriteLine("ERROR: Connection Failure!");
                return error;
            }
        }

        public void update(string pQuery)
        {
            Console.WriteLine(pQuery);

            try
            {
                //Open connection
                MySqlConnection sqlConnection = new MySqlConnection(connectionString);
                MySqlCommand sqlCommand = new MySqlCommand(pQuery, sqlConnection);
                sqlConnection.Open();
                //Reader class
                MySqlDataReader dataReader;
                dataReader = sqlCommand.ExecuteReader();
                while (dataReader.Read())
                {
                    Console.WriteLine(dataReader.ToString());
                }
                sqlConnection.Close(); //Close connection
            }
            catch
            {
                //error message when no connection
                Console.WriteLine("ERROR: Connection Failure!");
            }
        }
    }
}
