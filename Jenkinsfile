pipeline {
	agent any
	stages {
		stage ('Build') {
			steps {
				sh "make"
				sh "echo Done"
			}
		}
	}
	post {
		success {
			sh "make fclean"
			mail to: 'alex.strole004@gmail.com',
             			subject:"Succeeded! ${currentBuild.fullDisplayName}",
             			body: "Everything is good and great ${env.BUILD_URL}"
		}
		
		failure {
       			mail to: 'alex.strole004@gmail.com',
             			subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
             			body: "Something is wrong with ${env.BUILD_URL}"
		}
	}
}
