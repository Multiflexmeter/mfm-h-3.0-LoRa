pipeline {
  agent any
  stages {
    stage('Test native') {
      steps {
        sshagent(credentials: ['test-server-ssh-key']) {
            configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
              sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'pio lib install lib/*/ && pio test -e native\''
          }
        }
      }
    }
    stage('Test UNO') {
      steps {
        sshagent(credentials: ['test-server-ssh-key']) {
            configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
              sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'pio lib install lib/*/ && pio test -e uno\''
          }
        }
      }
    }
  }
}
